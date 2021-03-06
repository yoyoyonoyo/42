<?php
require '../config/database.php';

$name = $_POST['name'];
$email = $_POST['email'];
$pwd = $_POST['pwd'];
$pwd_confirm = $_POST['pwd-confirm'];

// Form verifications
if (!isset($email) || strlen($email) == 0 || strlen($email) > 64 || !filter_var($email, FILTER_VALIDATE_EMAIL)) {
    header("Location: /../signin.php?error=invalid_email&username=" . $name);
    exit();
} else if (!isset($name) || strlen($name) == 0 || strlen($name) > 24 || !preg_match("/^[a-zA-Z]+$/", $name)) {
    header("Location: /../signin.php?error=invalid_username&email=" . $email);
    exit();
} else if (!isset($pwd) || strlen($pwd) == 0 || strlen($pwd) > 64) {
    header("Location: /../signin.php?error=invalid_pwd&username=" . $name . "&email=" . $email);
    exit();
} else if (!preg_match("/^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,64}$/", $pwd)) {
    header("Location: /../signin.php?error=weak_pwd&username=" . $name . "&email=" . $email);
    exit();
} else if (!isset($pwd_confirm) || strlen($pwd_confirm) == 0 || $pwd_confirm !== $pwd) {
    header("Location: /../signin.php?error=pwds_no_match&username=" . $name . "&email=" . $email);
    exit();
}

$DB_DSN .= ";dbname=" . $DB_NAME;
// Connecting to 'instacam' database
try {
    $pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Searching if user already exists
try {
    $sql = "SELECT `name` FROM `users` WHERE `name`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$name]);
    $existing_user = $stmt->fetch();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

if ($existing_user !== false) {
    header("Location: /../signin.php?error=user_exists");
    exit();
}

// Inserting into 'users' table
try {
    $sql = "INSERT INTO `users` (`name`, `email`, `pwd`, `salt`)
                VALUES (?, ?, ?, ?);";
    $salt = substr(str_replace(['+', '/', '='], '', base64_encode(random_bytes(64))), 0, 64);
    $pdo->prepare($sql)->execute([$name, $email, hash_pbkdf2("sha256", $pwd, $salt, 40000), $salt]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Retrieving the ID of the new user
try {
    $sql = "SELECT `id` FROM `users` WHERE `name`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$name]);
    $res = $stmt->fetch();
    $new_id = $res['id'];
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Inserting into 'verify' table
try {
    $sql = "INSERT INTO `verify` (`user_id`, `phrase`)
                VALUES (?, ?);";
    $phrase = substr(str_replace(['+', '/', '='], '', base64_encode(random_bytes(64))), 0, 64);
    $pdo->prepare($sql)->execute([$new_id, $phrase]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Inserting into 'notifications' table
try {
    $sql = "INSERT INTO `notifications` (`user_id`)
                VALUES (?);";
    $pdo->prepare($sql)->execute([$new_id]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Inserting into 'passwords' table
try {
    $sql = "INSERT INTO `passwords` (`user_id`, `phrase`)
                VALUES (?, ?);";
    $pdo->prepare($sql)->execute([$new_id, ""]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

header("Location: mail_verify.php?id=" . $new_id);

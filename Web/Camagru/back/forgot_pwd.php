<?php
require '../config/database.php';

$email = $_POST['email'];

$DB_DSN .= ";dbname=" . $DB_NAME;
// Connecting to 'instacam' database
try {
    $pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
    $pdo->setAttribute(PDO::ERRMODE_EXCEPTION);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Searching for users with this email
try {
    $sql = "SELECT `id`, `email` FROM `users` WHERE `email`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$email]);
    $found_users = $stmt->fetchAll();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

var_dump($found_users);

foreach ($found_users as $found_user) {
    // Inserting into 'passwords' table
    try {
        $sql = "UPDATE `passwords` SET `phrase`=? WHERE `user_id`=?;";
        $phrase = substr(str_replace(['+', '/', '='], '', base64_encode(random_bytes(64))), 0, 64);
        $pdo->prepare($sql)->execute([$phrase, $found_user['id']]);
        echo "Phrase inserted.<br>";
    } catch (PDOEXCEPTION $e) {
        exit($e);
    }

    // Link mail_password.php will send
    $link = "http://localhost:8080/reset-pwd.php?id=" . $found_user['id'] . "&phrase=" . $phrase;
    echo $link . "<br>";
}

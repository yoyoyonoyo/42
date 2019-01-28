<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <title>Instacam</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" type="text/css" media="screen" href="css/index.css">
  <link rel="icon" type="image/x-icon" href="favicon.ico?v=1">
  <script>
    window.onscroll = function () { scrollFunction() };

    function scrollFunction() {
      if (document.body.scrollTop > 80 || document.documentElement.scrollTop > 80) {
        document.getElementById("navbar").style.padding = "10px 10px";
        document.getElementById("logo").style.fontSize = "30px";
      } else {
        document.getElementById("navbar").style.padding = "40px 10px";
        document.getElementById("logo").style.fontSize = "60px";
      }
    }
  </script>
</head>

<body>

  <div id="navbar">
    <a href="/index.php" id="logo" class="left-buttons">Instacam</a>
    <div id="navbar-right">
      <a href="/camera.php"><img src="/img/camera.png"></a>
      <a href="/index.php"><img src="/img/feed.png"></a>
      <a href="#account"><img src="/img/account.png"></a>
    </div>
  </div>
  <div id="feed">
    <?php for ($i = 0; $i < 1; $i++) {?>
    <div id="feed-box">
      <div id="feed-header">
        <div id="feed-user-pic" style="background-image: url('/resources/profile-pics/0.jpg');">
        </div>
        <div id="feed-user-login">
          <a href="#user">
            <p>florentklein</p>
          </a>
        </div>
        <div id="feed-date">
          <p>
            <?=date("D j, H:i");?>
          </p>
        </div>
      </div>
      <div id="feed-pic" style="background-image: url('/resources/feed-pics/0.jpg');">
      </div>
      <div id="feed-buttons">
        <button href="#" id="feed-like-button"><img src="/img/like.png" id="feed-buttons-img"><span id="feed-buttons-txt">J'aime</span></button>
        <button href="#" id="feed-like-button"><img src="/img/comment.png" id="feed-buttons-img"><span id="feed-buttons-txt">Commenter</span></button>
        <button href="#" id="feed-like-button"><img src="/img/share.png" id="feed-buttons-img"><span id="feed-buttons-txt">Partager</span></button>
      </div>
      <hr id="feed-bar">
      <div id="feed-likedby">
        <p>Aimé par <span>4 personnes</span></p>
      </div>
      <div id="feed-legend">
        <p><span>florentklein </span>À 42 avec @arnaudgissinger ! #errno</p>
      </div>
      <div id="feed-morecoms">
        <p>3 personnes ont commenté</p>
      </div>
      <div id="feed-comments">
        <p><span>shanacohen </span>Hey, c'est ma photo.</p>
        <p><span>yannisdoublet </span>Bonjour. Puis-je vous parler de notre Seigneur à tous, le Day06 de la PiscinePHP?</p>
        <p><span>tanguyboissel </span>Mdr, je vais tester les limites de cet espace commentaire :
          xdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxd</p>
        <p><span>etmoijaiuntreslongpseudooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
          </span>#relou</p>
        <p><span>florentklein </span>Merci...</p>
      </div>
    </div>
    <?php }?>
  </div>
  <div id="previous-next">
    <a href="#previous"><img src="/img/previous.png"></a>
    <a href="#next"><img src="/img/next.png"></a>
  </div>

</body>

</html>
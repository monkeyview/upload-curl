<?php
  $content = file_get_contents('php://input');
  $_POST = json_encode($content, true);
  if(isset($_POST['name']) && isset($_POST['age'])) {
    echo $_POST['name'] . " " . $_POST['age'];
  }
?>

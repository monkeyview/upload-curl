<?php
  $content = file_get_contents('php://input');
  //echo $content;
  print_r(json_decode($content, true));
?>

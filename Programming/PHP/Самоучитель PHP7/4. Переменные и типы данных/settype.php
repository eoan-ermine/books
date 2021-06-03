<?php
$str = "5wet";
settype($str, 'integer');
echo $str; // 5

echo '<br/>';

$flag = true;
settype($flag, 'string');
echo $flag; // 1

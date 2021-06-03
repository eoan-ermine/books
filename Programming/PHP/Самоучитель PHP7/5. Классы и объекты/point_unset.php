<?php
require 'point.php';
$point = new Point;
$point->x = 3;
$point->y = 7;
unset($point);
echo $point->x; // Notice: undefined variable: point

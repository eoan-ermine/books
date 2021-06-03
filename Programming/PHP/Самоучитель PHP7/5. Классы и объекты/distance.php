<?php
require_once '3d_point.php';

$lhs = new Point();

$lhs->x = 3;
$lhs->y = 4;
$lhs->z = 5;

$rhs = new Point();
$rhs->x = 6;
$rhs->y = 7;
$rhs->z = 8;

echo sqrt(($rhs->x ** 2 - $lhs->x ** 2) + ($rhs->y ** 2 - $lhs->y ** 2) + ($rhs->z ** 2 - $lhs->z ** 2));

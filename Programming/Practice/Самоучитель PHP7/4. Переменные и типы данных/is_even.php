<?php
$number = 15;

$flag = (float)($number / 2) - (int)($number / 2);

if($flag) { // true, т.к. $flag == 0.5
	echo '$number is even';
} else {
	echo '$number is odd';
}

<?php
// or/and is similar to ||/&& but have less priority
$flag1 = true;
$flag2 = false;
if($flag1 or $flag2) {
	echo '<p>One of flags is true</p>';
} else {
	echo '<p>Both flags are false</p>';
}

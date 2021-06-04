<?php
$number = 120;
switch(true)
{
	case ($number > 0 && $number <= 10):
		echo "$number less than 10 and greater than 0";
		break;
	case ($number > 10 && $number <= 100):
		echo "$number less than 100 and greater than 10";
		break;
	case ($number > 100 && $number <= 1000):
		echo "$number less than 1000 and greater than 100";
		break;
	default:
		echo "$number greater than 1000 or less than 0";
		break;
}

<?php
require_once('constant_class.php');

if(defined('ConstantClass::NAME')) {
	echo 'Constant is defined<br/>';
} else {
	echo 'Constant is not defined<br/>';
}

if(defined('ConstantClass::POSITION')) {
	echo 'Constant is defined<br/>';
} else {
	echo 'Constant is not defined<br/>';
}

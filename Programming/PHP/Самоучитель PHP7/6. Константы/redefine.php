<?php
if(define('VALUE', 'Hello, world')) {
	echo 'Константа VALUE получила значение "Hello, world!"<br/>';
}
if(define("VALUE", 1)) {
	echo 'VALUE set to 1<br/>';
}
echo VALUE;

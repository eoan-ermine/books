<?php
$str = '';

if(isset($str)) {
	echo 'Переменная $str существует<br/>';
}

$str = null;
if(isset($str)) {
	echo 'Переменная $str существует<br/>';
}

$a = 'variable';
$b = 'another variable';

if(isset($a)) {
	echo 'Переменная $a существует<br/>';
}
if(isset($a, $b)) {
	echo 'Переменные $a и $b существуют<br/>';
}

unset($a);

if(isset($a)) {
	echo 'Переменная $a существует<br/>';
}
if(isset($a, $b)) {
	echo 'Переменные $a и $b существуют<br/>';
}

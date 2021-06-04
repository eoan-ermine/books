<?php
if(file_get_contents('http://php.net')) {
	echo '<p>Имеется сетевой доступ</p>';
} else {
	echo '<p>Отсутствует сетевой доступ</p>';
}

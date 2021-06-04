<?php
($content = file_get_contents('http://php.net')) || exit('Error');
echo $content;

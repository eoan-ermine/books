<?php
$content = file_get_contents('http://php.net') or exit('Error');
echo $content

// or have less priority than =, so, first of all, content assigns to variable
// and then it checks if file_get_contents contains something

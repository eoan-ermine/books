<?php
$str = <<< HTML_END
Здесь располагается любой текст. До тех пор, пока не встретится
метка, можно писать все что угодно
HTML_END;
echo $str;

$name = "Имя пользователя";
$text = <<<'MARKER'
Переменные PHP не будут интерполироваться: $name
MARKER;

echo "<br/>" . $text;

<?php
$user = "Юрий";
$number = 123;
unset($user, $number);
echo $user; // Notice: Undefined variable

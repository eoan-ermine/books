<?php
file_put_contents(
	strftime("%F-%H-%M-%S", time() . '.txt'),
	mt_rand(0, mt_getrandmax())
);

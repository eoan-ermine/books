<?php
echo intval(42);		// 42
echo intval(4.2);		// 4
echo intval('42');		// 42
echo intval('+42');		// 42
echo intval('-42');		// -42
echo intval(042);		// 34
echo intval('042');		// 42
echo intval(1e10);		// 2147483647
echo intval('1e10');	// 1
echo intval(42000000);	// 42000000
echo intval(42, 8);		// 42
echo intval('42', 8);	// 34

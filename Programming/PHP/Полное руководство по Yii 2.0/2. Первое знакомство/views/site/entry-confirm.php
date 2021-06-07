<?php
use yii\helpers\Html;
?>
<p>Вы ввели следующую информацию:</p>
<ul>
    <li><label>Имя</label>: <?= Html::encode($model->name) ?></li>
    <li><label>Email</label>: <?= Html::encode($model->email) ?></li>
</ul>
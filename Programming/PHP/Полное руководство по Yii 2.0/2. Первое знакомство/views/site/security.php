<?php
use yii\helpers\Html;
use yii\helpers\HtmlPurifier;
?>

<-- To display a plain text -->
<div class="username">
    <?= Html::encode($user->name) ?>
</div>

<-- To display HTML content -->
<div class="post">
    <?= HtmlPurifier::process($post->text) ?>
</div>
<-- It's not fast, you should consider caching the filtering result -->

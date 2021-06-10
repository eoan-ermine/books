<?php
use app\components\HelloWidget;
?>
<?php HelloWidget::begin(); ?>

    sample content that may contain one or more <strong>HTML</strong> <pre>tags</pre>

    If this content grows too big, use sub views

    For e.g.

    <?php echo $this->render('about'); // Note: here render() method is of class \yii\base\View as this part of code is within view file and not in Widget class file ?>

<?php HelloWidget::end(); ?>
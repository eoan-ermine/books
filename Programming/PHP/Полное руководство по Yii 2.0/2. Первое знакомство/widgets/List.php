<?php
namespace app\widgets;

use yii\base\Widget;
use yii\helpers\Html;

class ListWidget extends Widget
{
    public $items = [];

    public function run()
    {
        return $this->render('list', [
            'items' => $this->items,
        ]);
    }
}
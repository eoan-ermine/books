<?php

namespace app\modules\forum;

class Module extends \yii\base\Module
{
    public function init()
    {
        parent::init();

        $this->modules = [
            'admin' => [
                'class' => 'app\modules\forum\modules\admin\Module',
            ]
        ]
    }
}
<?php
/**
 * @link http://www.yiiframework.com/
 * @copyright Copyright (c) 2008 Yii Software LLC
 * @license http://www.yiiframework.com/license/
 */

namespace app\assets;

use yii\web\AssetBundle;

/**
 * Main application asset bundle.
 *
 * @author Qiang Xue <qiang.xue@gmail.com>
 * @since 2.0
 */
class AppAsset extends AssetBundle
{
    public $basePath = '@webroot';
    public $baseUrl = '@web';

    // public $cssOptions = ['condition' => 'lte IE9'];
    // ^ Conditionally include a CSS file for browsers that are IE9 or below
    public $css = [
        'css/site.css',
    ];
    
    // public $jsOptions = ['position' => \yii\web\View::POS_HEAD];
    // ^ Force including of JS files in the head section of a page
    public $js = [
    ];
    
    public $depends = [
        'yii\web\YiiAsset',
        'yii\bootstrap\BootstrapAsset',
    ];
}

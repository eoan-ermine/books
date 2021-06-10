<?php

namespace app\models\records;

use yii\db\ActiveRecord;

class User extends ActiveRecord
{
    const SCENARIO_LOGIN = 'login';
    const SCENARIO_REGISTER = 'register';

    public function rules()
    {
        return [
            [['username', 'email', 'password'], 'required', 'on' => self::SCENARIO_REGISTER],
            [['username', 'password'], 'required', 'on' => self::SCENARIO_LOGIN],
            ['email', 'email'],
        ];
    }

    public function scenarios()
    {
        $scenarios = parent::scenarios();
        $scenarios[self::SCENARIO_LOGIN] = ['username', 'password'];
        $scenarios[self::SCENARIO_REGISTER] = ['username', 'email', 'password'];
        return $scenarios;
    }

    public function fields()
    {
        return [
            'id',
            'email' => 'email_address',
            // field name is "name", its value is defined by a PHP callback
            'name' => function() {
                return $this->first_name . ' ' . $this->last_name;
            }
        ];
    }

    // filter out some fields
    public function fields()
    {
        $fields = parent::fields();

        // remove fields that contain sensitive information
        unset($fields['auth_key'], $fields['password_hash'], $fields['password_reset_token']);

        return $fields;
    }
}
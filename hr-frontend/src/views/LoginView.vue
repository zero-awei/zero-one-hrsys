<template>
  <div class="container">
    <div class="login-box">
      <h1 class="login-title">基础管理系统</h1>
      <el-form :model="formData" ref="form" class="login-form">
        <el-form-item>
          <div class="input-container">
            <label class="el-form-item__label">账号</label>
            <el-input v-model="formData.username" class="login-input"></el-input>
          </div>
        </el-form-item>
        <el-form-item>
          <div class="input-container">
            <label class="el-form-item__label">密码</label>
            <el-input v-model="formData.password" type="password" class="login-input"></el-input>
          </div>
        </el-form-item>
        <el-form-item>
          <div class="input-container">
            <label class="el-form-item__label">验证码</label>
            <div class="vc-input-container">
              <el-input v-model="formData.vertification" type="text" class="vc-input"></el-input>
            </div>
          </div>
        </el-form-item>
        <el-form-item>
          <el-button type="primary" class="login-button" @click="submitForm">登录</el-button>
        </el-form-item>
        <el-form-item>
          <div class="other-login">
            <span class="other-login-text">其他登录方式</span>
            <div class="login-icons">
              <div class="login-icon" @click="showQQAuth">
                <img src="http://ehrpcm.ibizlab.cn/assets/img/QQ.svg" alt="QQ" class="login-icon-img">
              </div>
              <div class="login-icon" @click="showWechatAuth">
                <img src="http://ehrpcm.ibizlab.cn/assets/img/weixin.svg" alt="微信" class="login-icon-img">
              </div>
            </div>
          </div>
        </el-form-item>
      </el-form>
      <!-- TODO[TEST_CODE]: 测试代码后期发布需要删除 -->
      <hr/>
      <router-link to="/sample" class="sample-link">进入示例演示页面</router-link>
    </div>
  </div>
  <!-- 验证码组件 -->
  <Verify
    mode="pop"
    :captchaType="captchaType.value"    
    :imgSize="{ width: '400px', height: '200px' }"
    ref="verify"
    @success="handleSuccess"
  ></Verify>
</template>

<script setup>
import Verify from '@/components/verifition/Verify.vue'
import Request from '@/apis/request'
// import { ref, reactive } from 'vue'
import { login } from '@/apis/login'
import { ElMessage } from 'element-plus'
import { useRouter } from 'vue-router'

// 获取router对象
const $router = useRouter()

// 定义登录数据对象
const formData = reactive({
  username: 'admin',
  password: '123456'
})

/**
 * 执行登录
 * @param code 验证码字符串
 */
function doLogin(code) {
  // 发送登录请求
  login(
    {
      ...formData,
      clientId: import.meta.env.VITE_CLIENT_ID,
      code: code
    },
    () => {
      // 跳转到首页
      $router.push('/home')
      // 登录成功提示
      ElMessage.success('登录成功，前往首页')
    },
    () => {
      ElMessage.error('账号或密码错误')
    }
  )
}

// 定义登录提交函数
function submitForm() {
  //TODO[TEST_CODE]:测试直接进入主界面
  // $router.push('/home')

  // 弹出验证码框
  // useVerify('blockPuzzle')

  //TODO[TEST_CODE]:测试登录
  doLogin('dddd')
}

// 验证码组件引用
const verify = ref(null)

// 验证码类型
const captchaType = ref('')

/**
 * 弹出验证码框
 * @param type 验证码类型 blockPuzzle滑块验证 clickWord点击文字验证
 */
function useVerify(type) {
  captchaType.value = type
  verify.value.show()
}

/**
 * 验证码验证通过执行登录二次验证逻辑
 * @param res 验证通过信息
 */
function handleSuccess(res) {
  //TODO[TEST_CODE]:测试调用二次验证
  Request.requestForm(
    Request.POST,
    '/login',
    { captchaVerification: res.captchaVerification },
    { baseURL: import.meta.env.VITE_CAPTCHA_URL }
  )
    .then((res) => {
      console.log(res)
      if (res.data.repCode === '0000') {
        // 跳转到首页
        $router.push('/home')
        // 登录成功提示
        ElMessage.success('登录成功，前往首页')
        return
      }
      ElMessage.error('账号或密码错误')
    })
    .catch((res) => {
      console.log(res)
      ElMessage.error('账号或密码错误')
    })

  doLogin(res.captchaVerification)
}
/**
 * 弹出QQ授权登录提示
 */
 function showQQAuth() {
  ElMessage.info('QQ授权登录暂未支持');
}

/**
 * 弹出微信授权登录提示
 */
function showWechatAuth() {
  ElMessage.info('微信授权登录暂未支持');
}
</script>

<style>
.container {
  display: flex;
  background-image: url("../../images/loginimg.jpeg");
  background-size:210vb 100vh ;
  background-position: center;
  background-repeat: no-repeat;
  justify-content: center;
  align-items: center;
  height: 100vh;
}

.login-box {
  width: 420px;
  margin: 50px auto;
  padding: 20px;
  background-color: #ffffff;
  box-shadow: 0 6px 20px rgba(0, 0, 0, 0.1);
  border-radius: 10px;
}

.login-title {
  font-size: 24px;
  color: #666666;
  margin-top: 20px;
  text-align: center;
  margin-bottom: 30px;
}

.login-form {
  margin-top: 35px;
}

.login-input {
  height: 40px;
  font-size: 20px;
  color: #333333;
  border: none;
  border-radius: 4.8px;
  padding-left: 10px;
}

.vc-input-container {
  display: flex;
  align-items: center;
}

.vc-input {
  height: 40px;
  font-size: 20px;
  color: #333333;
  border: none;
  border-radius: 4.8px;
  padding-left: 10px;
  width: 150px;
}

.login-button {
  height: 40px;
  width: 110px;
  font-size: 20px;
  margin: 10px auto 0px;
  background-color: #4460f1;
  border-color: #4460f1;
}

.login-button:hover {
  background-color: #747b8b;
  border-color: #3c56d7;
}

.other-login {
  display: flex;
  justify-content: center;
  align-items: center;
  margin-top: -5px;
}

.other-login-text {
  font-size: 16px;
  color: #999999;
}

.login-icons {
  display: flex;
  justify-content: center;
  align-items: center;
  margin-top:10px;
}

.login-icon {
  width: 40px;
  height: 40px;
  border-radius: 50%;
  margin: 0 10px ;
  display: flex;
  justify-content: center;
  align-items: center;
  cursor: pointer;
}

.login-icon-img {
  width: 36px;
  height: 36px;
}
.sample-link {
  display: block;
  text-align: center;
  margin-top: 10px;
  font-size: 18px;
  color: #26d94d;
  text-decoration: none;
}
</style>

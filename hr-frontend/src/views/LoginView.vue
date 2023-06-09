<template>
  <div class="box">
    <div class="container">
      <div class="login-box">
        <h1 class="login-title">人力资源管理系统</h1>
        <el-form :model="formData" ref="form" class="login-form">
          <el-form-item>
            <div class="input-container">
              <label class="el-form-item__label">账号</label>
              <el-input
                v-model="formData.username"
                class="login-input"
              ></el-input>
            </div>
          </el-form-item>
          <el-form-item>
            <div class="input-container">
              <label class="el-form-item__label">密码</label>
              <el-input
                v-model="formData.password"
                type="password"
                class="login-input"
              ></el-input>
            </div>
          </el-form-item>
          <el-form-item>
            <el-button type="primary" class="login-button" @click="submitForm"
              >登录</el-button
            >
          </el-form-item>
        </el-form>
        <!-- TODO[TEST_CODE]: 测试代码后期发布需要删除 -->
        <!-- <hr/>
        <router-link to="/sample" class="sample-link">进入示例演示页面</router-link> -->
      </div>
    </div>
  </div>
  <!-- 验证码组件 -->
  <Verify
    mode="pop"
    :captchaType="captchaType"
    :imgSize="{ width: '400px', height: '200px' }"
    ref="verify"
    @success="handleSuccess"
  ></Verify>
</template>

<script setup>
import Verify from '@/components/verifition/Verify.vue'
import Request from '@/apis/request'
import { ref, reactive } from 'vue'
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
  useVerify('clickWord')

  //TODO[TEST_CODE]:测试登录
  // doLogin('dddd')
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
  // Request.requestForm(
  //   Request.POST,
  //   '/login',
  //   { captchaVerification: res.captchaVerification },
  //   { baseURL: import.meta.env.VITE_CAPTCHA_URL }
  // )
  //   .then((res) => {
  //     console.log(res)
  //     if (res.data.repCode === '0000') {
  //       // 跳转到首页
  //       $router.push('/home')
  //       // 登录成功提示
  //       ElMessage.success('登录成功，前往首页')
  //       return
  //     }
  //     ElMessage.error('账号或密码错误')
  //   })
  //   .catch((res) => {
  //     console.log(res)
  //     ElMessage.error('账号或密码错误')
  //   })

  doLogin(res.captchaVerification)
}
</script>

<style>
.box {
  width: 100vw;
  height: 100vh;
  background-color: rgb(29, 67, 89);
}
.container {
  display: flex;
  background-image: url('../../images/login_two.jpg');
  background-size: 77vw 90vh;
  background-position: center;
  background-repeat: no-repeat;
  justify-content: center;
  align-items: center;
  height: 100vh;
}

.login-box {
  display: block;
  width: 25vw;
  position: absolute;
  right: 17%;
  top: 50%;
  transform: translateY(-50%);
  margin: 0;
  padding: 0;
}
.input-container {
  display: block;
  width: 25vw;
}

.login-title {
  font-size: 24px;
  color: #666666;
  margin-top: 20px;
  text-align: center;
  margin-bottom: 30px;
}

.el-form-item__label {
  color: rgb(81, 100, 115);
  display: block;
  margin: 5px 20px;
  font-weight: 100;
  font-size: 18px;
}
.el-input__wrapper {
  height: 50px;
  width: 350px;
  border: 1px solid rgb(214, 222, 228);
  border-radius: 40px;
  margin: 0;
  box-sizing: border-box;
  font-size: 20px;
  font-weight: 200;
  color: #333333;
  padding: 20px;
}
.login-button {
  height: 40px;
  width: 350px;
  font-size: 20px;
  margin: 10px auto 0px;
  background-color: #102940;
  border-color: #4460f1;
  border-radius: 40px;
}

.login-button:hover {
  background-color: #747b8b;
  border-color: #3c56d7;
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

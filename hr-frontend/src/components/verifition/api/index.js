import Request from '@/apis/request'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = import.meta.env.VITE_CAPTCHA_PREFIX

//获取验证图片以及token
export function reqGet(data) {
  return Request.requestJson(Request.POST, currBaseUrl + '/get', data, {
    baseURL: import.meta.env.VITE_CAPTCHA_URL
  })
}

//滑动或者点选验证
export function reqCheck(data) {
  return Request.requestJson(Request.POST, currBaseUrl + '/check', data, {
    baseURL: import.meta.env.VITE_CAPTCHA_URL
  })
}

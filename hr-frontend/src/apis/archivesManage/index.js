import Request from '../request'
import { userInfoStore } from '@/stores/user'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = '/achievesmanage/'

/**
 * 登录接口
 * @param data 档案信息数据
 * @param success 成功回调
 * @param fail 失败回调
 */
export const login = (data, success, fail) => {
  const $store = userInfoStore()
  Request.requestForm(Request.POST, currBaseUrl + '', data)
    .then((data) => {
      if (data.data) {
        // $store.setToken(data.data)
        // 执行成功回调
        // success()
        return
      }
      // 执行失败回调
      fail()
    })
    .catch((err) => {
      // 打印错误信息
      console.warn(err)
      // 执行失败回调
      fail()
    })
}

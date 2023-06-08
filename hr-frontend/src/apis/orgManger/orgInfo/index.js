import Request from '@/apis/request'
import { orgInfoStore } from '@/stores/orgInfo'

// 定义一个功能模块基础url，方便替换
const currBaseUrl = import.meta.env.VITE_HR_J3_2
/**
 * 通用接口
 * @param data 登录数据
 * @param success 登录成功回调
 * @param fail 登录失败回调
 */
export const addOrgInfo = (data, success, fail) => {
  Request.requestJson(Request.POST, currBaseUrl + '/add-org-info', data)
    .then((data) => {
      console.log(data)
      // 记录Token到本地
      if (data.data) {
        // 执行成功回调
        success()
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

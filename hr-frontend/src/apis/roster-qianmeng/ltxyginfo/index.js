import { RetireStaffStore } from '@/stores/retirement'
import Request from '../request'

const baseUrl = import.meta.env.VITE_HR_C2_2
/**
 * 通用接口
 * @param data 数据
 * @param success 成功回调
 * @param fail 失败回调
 */

//离退休人员:
/**
 * 参数:
 * pageIndex
 * pageSize
 * -----------
 * idAndname
 * ygbh
 * pimpersonname
 */

/* 响应:
{
  "code": 10000,
  "message": "success",
  "data": {
    "pageIndex": 1,
    "pageSize": 5,
    "total": 0,
    "pages": 0,
    "rows": []
  }
}
 */

//分页查询离退休员工信息
export const getLtxygData = (data, success, fail) => {
  const $store = RetireStaffStore()
  Request.requestJson(Request.GET, baseUrl + '/query-CheckRetiresList', data)
    .then((data) => {
      if (data.data) {
        //存token
        $store.setToken(data.data)
        success()
        {
          return
        }
      }
      fail()
    })
    .catch((err) => {
      console.warn(err)
      fail()
    })
}

//导出离退休人员
export const exportLtxygData = (data, success, fail) => {
  const $store = RetireStaffStore()
  Request.requestJson(Request.GET, baseUrl + '/query-ExportRetirees', data)
    .then((data) => {
      if (data.data) {
        //存token
        $store.setToken(data.data)
        success()
        {
          return
        }
      }
      fail()
    })
    .catch((err) => {
      console.warn(err)
      fail()
    })
}

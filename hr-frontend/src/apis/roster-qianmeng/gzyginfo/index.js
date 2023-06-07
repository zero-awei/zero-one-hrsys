import { TemporaryStaffStore } from '@/stores/temporyStaff'
import Request from '../request'

const baseUrl = import.meta.env.VITE_HR_C2_2
/**
 * 通用接口
 * @param data 数据
 * @param success 成功回调
 * @param fail 失败回调
 */

//挂职员工:
/**
 * 参数:
 * pageIndex
 * pageSize
 * idandname
 * ---------
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

//分页查询挂职员工信息
export const getGzygData = (data, success, fail) => {
  const $store = TemporaryStaffStore()
  Request.requestJson(Request.GET, baseUrl + '/query-tempstaff', data)
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
export const exportGzygData = (data, success, fail) => {
  const $store = TemporaryStaffStore()
  Request.requestJson(Request.GET, baseUrl + '/get-tempstaff', data)
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

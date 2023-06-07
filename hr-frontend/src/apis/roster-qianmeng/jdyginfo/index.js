import { RentStaffStore } from '@/stores/jdyg'
import Request from '../request'

const baseUrl = import.meta.env.VITE_HR_C2_2
/**
 * 通用接口
 * @param data 数据
 * @param success 成功回调
 * @param fail 失败回调
 */

//借调人员表单:
/**
 * 参数:
 * pageIndex
 * pageSize
 * -----------
 * idAndName（模糊）
 * pimPersonName
 * ygbh
 * zz
 * bm
 * zw
 * gw
 * fp
 * lx
 * fpzt
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

//分页查询借调员工信息
export const getJdygData = (data, success, fail) => {
  const $store = RentStaffStore()
  Request.requestJson(Request.GET, baseUrl + '/query-LoanedPerPage', data)
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

//导出借调人员
export const exportJdygData = (data, success, fail) => {
  const $store = RentStaffStore()
  Request.requestJson(Request.GET, baseUrl + '/get-loanedPer', data)
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

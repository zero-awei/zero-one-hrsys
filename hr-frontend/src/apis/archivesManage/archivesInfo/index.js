import Request from '../request'
import { userStore } from '@/stores/user'

//分页查询组织列表
const currBaseUrl = '/common/'

/**
 * 通用接口
 * @param data 数据
 * @param success 成功回调
 * @param fail 失败回调
 */
export const association = (data, success, fail) => {
  const $store = userStore()
  Request.requestForm(Request.GET, currBaseUrl + 'query-name-of-association', data)
    .then((data) => {
      // 记录侧边栏数据到本地
      if (data.data) {
        $store.setToken(data.data)
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

//分页查询员工信息
const currBaseUrl2 = '/archives'
export const archives = (data, success, fail) => {
  const $store = userStore()
  Request. requestJson(Request.GET, currBaseUrl2, data)
    .then((data) => {
      // 记录Token到本地
      if (data.data) {
        $store.setToken(data.data)
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


//分页查询员工信息
export const archives = (data, success, fail) => {
  const $store = userStore()
  Request. requestJson(Request.GET, currBaseUrl2, data)
    .then((data) => {
      // 记录Token到本地
      if (data.data) {
        $store.setToken(data.data)
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


// 1.查询组织结构树
// 2.分页查询组织列表  GET common/query-name-of-association ✓
// {
// 	"code": 10000,
// 	"data": [
// 		{
// 			"key": 1,  //列表项编号	integer(int32)	

// 			"value": "身份证"   //列表项值	string
// 		}
// 	],
// 	"message": "提示消息内容"
// }


// 3.分页查询员工信息（用于输入条件中选择员工）
// {
//   "code": 10000,
//   "message": "success",
//   "data": {
//     "pageIndex": 1, //查询页码
//     "pageSize": 5, //查询条数
//     "total": 0,  //总条数
//     "pages": 0,  //总页数
//     "rows": []   //当当前页数据列表
//   }
// }

// 分页查询档案列表
// {
//   id	string
//   编号
  
//   name	string
//   姓名
  
//   dabh	string
//   档案编号
  
//   ormorgid3	string
//   管理单位
  
//   dabgd	string
//   档案保管地
  
//   archivescenterid	string
//   档案室
  
//   education	string
//   档案学历
  
//   dateofbirth	string
//   档案出生日期
  
//   joinpartydate	string
//   档案入党时间
  
//   startworkdatae	string
//   档案参加工作时间
  
//   dazt	string
//   档案状态
  
//   }]}

// 分页查询档案室
// /pull-list/archives-level  GET  json
// {
//   "code": 10000,
//   "message": "success",
//   "data": {
//     "levelsList": []
//   }

// 新建档案
// 删除档案（支持批量删除）
// 查询指定档案详情
// 更新指定档案
import Request from '../request'
import { userStore } from '@/stores/user'

//纯数据处理可以在strore里面写，如果要和界面交互就写api里面
//分页查询组织列表
const baseUrl = import.meta.env.VITE_HR_C1_4 //proj-tag
/**
 * 通用接口
 * @param data 数据
 * @param success 成功回调
 * @param fail 失败回调
 */
export const association = (data, success, fail) => {
  // const $store = userStoreInfo()
  // Request.requestJson(Request.GET, baseUrl + 'query-org-page', data)
  //   .then((data) => {
  //     // 获取侧边栏数据
  //     if (data.data) {
  //       // $store.setToken(data.data)
  //       // 执行成功回调
  success()  //传参与页面进行交互，后期将上面的注释解开即可
  return
  // }
  // 执行失败回调
  fail()
  // })
  // .catch((err) => {
  //   // 打印错误信息
  //   console.warn(err)
  //   // 执行失败回调
  //   fail()
  // })
}

//分页查询员工信息
// const currBaseUrl2 = '/employee-info/'
// export const employeeInfo = (data, success, fail) => {
//   const $store = userStore()
//   Request. requestJson(Request.GET, currBaseUrl2+'employee-query', data)
//     .then((data) => {
//       // 获取员工信息
//       if (data.data) {

//         // 执行成功回调
//         success()
//         return
//       }
//       // 执行失败回调
//       fail()
//     })
//     .catch((err) => {
//       // 打印错误信息
//       console.warn(err)
//       // 执行失败回调
//       fail()
//     })
// }

//分页查询档案列表   get json
// const currBaseUrl3 = '/archives'
// export const archivelist = (data, success, fail) => {
//   const $store = userStore()
//   Request. requestJson(Request.GET, currBaseUrl3, data)
//     .then((data) => {
//       // 获取档案数据列表
//       if (data.data) {

//         // 执行成功回调
//         success()
//         return
//       }
//       // 执行失败回调
//       fail()
//     })
//     .catch((err) => {
//       // 打印错误信息
//       console.warn(err)
//       // 执行失败回调
//       fail()
//     })
// }




// 1.查询组织结构树  ✓  /organization-department-tree-structure/sector-org-query  get json
// {
//   "code": 10000,
//   "message": "success",
//   "data": {
//     pageIndex：;   //当前页码
       pageSize: ;  //每页数据条数
       total: ;  //数据的总条数
       pages: ;  //数据的总页数
//当前页数据列表
//     "rows": [{
    //          orgsectorname	string
    //          组织名字
    
    //          orgsectorid	string
    //          部门id
    
    //          orgname	string
    //          组织名字
    
    //          orgid	string
    //          组织id
    
    //     }
// ]

// 2.分页查询组织列表  
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


// 3.分页查询员工信息（用于输入条件中选择员工）  ✓  
// ​/employee-information​/page-query get json
// {
//   "code": 10000,
//   "message": "success",
//   "data": {
//     pageIndex：;   //当前页码
       pageSize: ;  //每页数据条数
       total: ;  //数据的总条数
       pages: ;  //数据的总页数
       //当前页数据列表
//     "rows": [{
//           name	string
//           员工姓名

//           sex	string
//           性别

//           age	integer
//           minimum: 0
//           maximum: 4294967295
//           年龄

//           id	integer
//           员工编号

//           organize	string
//           组织

//           depart	string
//           部门

//           job	string
//           职务

//           post	string
//           岗位

//           idMum	string
//           bitrhday	string
//           phone	string
//           手机号码

//           state	string
//           员工状态

// }]
//   }
// }

//4. 分页查询档案列表  ✓

// {
//   "code": 10000,
//   "message": "success",
//   "data": {
//     pageIndex：;   //当前页码
       pageSize: ;  //每页数据条数
       total: ;  //数据的总条数
       pages: ;  //数据的总页数
       //当前页数据列表
//     "rows": [{
//            id	string
//            编号
    
//            name	string
//            姓名
    
//            dabh	string
//            档案编号
    
//            ormorgid3	string
//            管理单位
    
//            dabgd	string
//            档案保管地
    
//            archivescenterid	string
//            档案室
    
//            education	string
//            档案学历
    
//            dateofbirth	string
//            档案出生日期
    
//            joinpartydate	string
//            档案入党时间
    
//            startworkdatae	string
//            档案参加工作时间
    
//            dazt	string
//            档案状态
    
//            }
//        ]
//   }
// }

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
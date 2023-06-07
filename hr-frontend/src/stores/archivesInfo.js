import { defineStore } from 'pinia'
// import Request from '@/apis/request'

export const useInfoStore = defineStore('archivesInfo', {
    state: () => ({
        //记录侧边栏菜单
        menus: null,
        //配置功能按键
        show:false,
        tableOperations: [
            {
                name: '新增'
            },
            // {
            //     name: '编辑'
            // }, 
            // {          
            //     name: '过滤'
            // }
        ],
        //记录表格表名
        tableTitle: '档案信息',
        //新增按钮表单表名
        addTitle: '档案信息',
        //新增表单所需栏目
        dataitem: null,
        //记录表单数据
        xmlData: [
            { id: 1, name: '档案编号', prop: 'id' },
            { id: 2, name: '管理单位', prop: 'name' },
            { id: 3, name: '档案保管地', prop: 'dabgd' },
            { id: 4, name: '档案室', prop: 'archivesRoom' },
            { id: 5, name: '档案状态', prop: 'fileStatus' },
            { id: 6, name: '员工编号', prop: 'employeeNumber' },
            { id: 7, name: '员工姓名', prop: 'employeeName' },
            { id: 8, name: '员工状态', prop: 'state' },
            { id: 9, name: '所属单位', prop: 'unit' },
            { id: 10, name: '档案未转出月数', prop: 'months' },
            { id: 11, name: '档案借阅状态', prop: 'loanStatus' }
        ],
        //记录表格数据
        tableData: null,
        // 用户信息
        userData: null,
        // 每页数据条数
        pageSizes: [],
        //总数据条数
        total: null,
        messageInfo: ref('确定删除吗？'),
        messageSuccess: ref('删除成功'),
        messageError: ref('取消')
        // baseUrl :import.meta.env.VITE_HR_C1_4 //proj-tag
    }),
    actions: {
        //加载侧边栏菜单--查询组织结构树
        asideData() {
            //发送请求获取表单所需栏目
            // let data = await Request.requestForm(
            //   Request.GET,
            //    baseUrl + 'query-org-page',
            //    data,
            //    null
            // )
            //const rows=data.data.rows 
            //接口可用后，将测试数据注释掉即可
            const rows = [
                {
                    path: '/sample',
                    text: '员工信息',
                    icon: 'user'
                },
                {
                    path: '/sample/excel',
                    text: '分配信息',
                    icon: 'user'
                },
                {
                    path: '/sample/print',
                    text: '教育信息',
                    icon: 'user'
                },
                {
                    path: '/sample/edit',
                    text: '语言能力',
                    icon: 'user'
                },
                {
                    path: '/sample/sass',
                    text: '家庭情况',
                    icon: 'user'
                },
                {
                    path: '/sample/communication',
                    text: '工作履历',
                    icon: 'user'
                },
                {
                    path: '/sample/pagination',
                    text: '档案信息',
                    icon: 'user'
                },
                {
                    path: '/sample/sass',
                    text: '绩效信息',
                    icon: 'user'
                },
                {
                    path: '/sample/communication',
                    text: '考勤信息',
                    icon: 'user'
                },
                {
                    path: '/sample/pagination',
                    text: '合同信息',
                    icon: 'user'
                },
                {
                    path: '/sample/sass',
                    text: '证书信息',
                    icon: 'user'
                },
                {
                    path: '/sample/communication',
                    text: '奖励惩罚',
                    icon: 'user'
                },
                {
                    path: '/sample/pagination',
                    text: '培训记录',
                    icon: 'user'
                },
                {
                    path: '/sample/sass',
                    text: '军转干部',
                    icon: 'user'
                },
                {
                    path: '/sample/communication',
                    text: '学术成果',
                    icon: 'user'
                },
            ]
            this.menus = rows
        },

        //根据搜索内容筛选数据
        // filter(val) {
        //     //未完
        // },

        //初始化表格
        async initTableData() {
            // 发送请求获取表格数据
            // let data = await Request.requestForm(
            //   Request.GET,
            //   '/archives/archivesInfo/',
            //   data
            // )
            // const rows= data.data.rows
            const rows = [
                {
                    id: '001',
                    name: '某大型集团公司',
                    dabgd: '公司本部',
                    archivesRoom: '档案室1111上层1',
                    fileStatus: '有效',
                    employeeNumber: 1921,
                    employeeName: 'sxj',
                    state: '有效',
                    unit: '培训管理',
                    months: 5,
                    loanStatus: '借阅中'
                },
                {
                    id: '002',
                    name: '某大型集团公司',
                    dabgd: '公司本部',
                    archivesRoom: '档案室1111上层1',
                    fileStatus: '有效',
                    employeeNumber: 1921,
                    employeeName: 'sxj',
                    state: '有效',
                    unit: '培训管理',
                    months: 11,
                    loanStatus: '已归还'
                }
            ]
            this.tableData = rows
        },

        //新增档案
        addConfig() {
            // 发送请求获取新增配置项数据
            // let data = await Request.requestForm(
            //   Request.GET,
            //   '/archives/archivesInfo/',
            //   data
            // )
            // const rows= data.data.rows
            const rows = reactive([
                //档案信息
                //借阅信息
                {
                    label: '借阅人',
                    name: 'borrower',
                    type: String,
                },
                {
                    label: '借阅时间',
                    name: 'borrowingTime',
                    type: Date,
                },
                {
                    label: '归还时间',
                    name: 'returnTime',
                    type: Date,
                },
                {
                    label: '审批人',
                    name: 'approver',
                    type: String,
                },
                {
                    label: '审批时间',
                    name: 'approverTime',
                    type: Date,
                },
                {
                    label: '借阅原因',
                    name: 'borrowReason',
                    type: String,
                },
                {
                    label: '状态',
                    name: 'catalogeType',
                    type: Array,
                    options: [
                        {
                            id: 1,
                            optionData: "借阅中"
                        },
                        {
                            id: 2,
                            optionData: "已归还"
                        },
                    ]
                },
                //调档记录
                {
                    label: '调档记录类型',
                    name: 'recordType',
                    type: String,
                },
                {
                    label: '调出单位',
                    name: 'outUnit',
                    type: String,
                },
                {
                    label: '调入单位',
                    name: 'transferUnit',
                    type: String,
                },
                {
                    label: '调动时间',
                    name: 'transferTime',
                    type: String,
                },
                {
                    label: '备注',
                    name: 'remark',
                    type: Text,
                },
            ])
            this.dataitem = rows
        },

        //请求待定
        addData(val) {
            this.tableData.push(val)
        },

        editInfo() {
            // 发送请求获取档案数据-新建档案接口
            // let data = await Request.requestForm(
            //   Request.GET,
            //   '/archives/archivesInfo/',
            //   data
            // )
            // const rows= data.data.rows
            const rows = reactive({
                //档案信息
                basicInfo: {
                    ename: '鸽鸽',
                    IDType: '居民身份证',
                    birth: '2000-01-01',
                    sex: '武装直升机',
                    birthplace: '北京市丰台区',
                    empno: '008',
                    IDNumber: '101111197001012132',
                    age: '18',
                    nation: '赛博坦',
                    marriage: '未婚',
                    politicalLandscape: '群众',
                },
                //借阅信息
                workRecord: [
                    {
                        employmentDate: '2018-05-03',
                        endOfOffice: '2016-05-03',
                        workUnit: '一局',
                        department: '技术组',
                        post: '技术员',
                        grade: '组长'
                    }
                ],
                //调档记录
                additionalInfo: {
                    householdRegistrationType: '非农业户口',
                    domicile: '北京市',
                    birthplace: '北京市西城区',
                    healthCondition: '良好',
                    hobbies: '听音乐',
                    BloodType: 'AB',
                    isOnlyChild: '是',
                    mailingAddress: '北京市',
                    entryChannel: '军人安置',
                    employeeStatus: '见习',
                    blacklisted: ''
                },
            })
            this.userData = rows
        },

        //消息弹框
        changeMessage(row, column) {
            //发送请求获取提示信息数据
            // let data = await Request.requestForm(
            //   Request.GET,
            //    baseUrl + 'query-org-page',
            //    data,
            // )
            //const message=data.message 
            const mitt = getCurrentInstance().appContext.config.globalProperties.$bus
            const messageInfo = this.messageInfo
            const messageError=this.messageError
            const messageSuccess=this.messageSuccess
            const message = reactive({ messageInfo, messageSuccess, messageError })
            //修改数据后点击遮罩层，会显示关闭提醒的弹出框
            //点击某一列执行，利用column中的label属性，例如点击Action这一列
            if (column.label === 'Action') {
                //执行逻辑
                mitt.emit('changeInfo', message)
            }
        },

        //成功提示-保存成功
        changeSaveValue() {
            //发送请求获取提示信息数据
            // let data = await Request.requestForm(
            //   Request.GET,
            //    baseUrl + 'query-org-page',
            //    data,
            // )
            //const message=data.message 
            const mitt = getCurrentInstance().appContext.config.globalProperties.$bus
            const success = ref('成功')
            const warn = ref('请配置数据导入项')
            const error = ref('值规则校验异常')
            const message = reactive({
                success,
                error,
                warn
            })
            const messageInfo = message
            //可修改提示内容
            // message.success=''
            mitt.emit('showSuccess', messageInfo.success)
        },

        //警告提示-导入配置项
        changeImportValue() {
            //发送请求获取提示信息数据
            // let data = await Request.requestForm(
            //   Request.GET,
            //    baseUrl + 'query-org-page',
            //    data,
            // )
            //const message=data.message 
            const mitt = getCurrentInstance().appContext.config.globalProperties.$bus
            const success = ref('成功')
            const warn = ref('请配置数据导入项')
            const error = ref('值规则校验异常')
            const message = reactive({
                success,
                error,
                warn
            })
            const messageInfo = message
            mitt.emit('showError', messageInfo.error)
        },

        //出错提示-输入项为空
        changeWarnValue() {
            //发送请求获取提示信息数据
            // let data = await Request.requestForm(
            //   Request.GET,
            //    baseUrl + 'query-org-page',
            //    data,
            // )
            //const message=data.message 
            const mitt = getCurrentInstance().appContext.config.globalProperties.$bus
            const success = ref('成功')
            const warn = ref('请配置数据导入项')
            const error = ref('值规则校验异常')
            const message = reactive({
                success,
                error,
                warn
            })
            const messageInfo = message
            mitt.emit('showWarn', messageInfo.warn)
        }

    }
})

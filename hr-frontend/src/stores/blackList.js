import { defineStore } from 'pinia'
// import Request from '@/apis/request'

export const useBlackListStore = defineStore('blackList', {
    state: () => ({
        //记录侧边栏菜单
        menus: null,
        //消息弹出框初始设为不显示
        show: false,
        //配置功能按键
        tableOperations: null,
        //记录表格表名
        tableTitle: '黑名单',
        //新增按钮表单表名
        addTitle: '黑名单列表',
        //新增表单所需栏目
        dataitem: null,
        //记录表单数据
        xmlData: [
            { id: 1, name: '员工编号', prop: 'id' },
            { id: 2, name: '员工姓名', prop: 'name' },
            { id: 3, name: '组织', prop: 'organization' },
            { id: 4, name: '部门', prop: 'department' },
            { id: 5, name: '职务', prop: 'position' },
            { id: 6, name: '岗位', prop: 'job' },
            { id: 7, name: '证件号码', prop: 'certificateId' },
            { id: 8, name: '出生日期', prop: 'certificateId' },
            { id: 9, name: '年龄', prop: 'age' },
            { id: 10, name: '手机号码', prop: 'phoneNumber' },
            { id: 11, name: '员工状态', prop: 'state' }
        ],
        //记录表格数据
        tableData: null,
        //按表单类型设置的数据
        data: null,
        // 用户信息
        userData: null,
        // 每页数据条数
        pageSize: [],
        //总数据条数
        total: null,
        //当前页
        currentPage: null
    }),
    actions: {
        //加载侧边栏菜单-查询组织结构树/分页查询组织列表
        asideData() {
            //发送请求获取侧边栏数据
            // let data = await Request.requestForm(
            //   Request.GET,
            //   '/login/current-user',
            //    null
            // )
            //const rows=data.data.rows 
            //console.log(data)
            //测试数据
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

        // 根据过滤器结果，发送请求
        requestRes(data) {
            //发送请求获取过滤后的表格
            // let data = await Request.requestForm(
            //   Request.GET,
            //   '/login/current-user',
            //    null
            // )
            //console.log(data)
            //const filterData=data.data
            const filterData = reactive({
                employeeName: {
                    name: '员工姓名',
                    type: 'input'
                },
                employeeNum: {
                    name: '员工编号',
                    type: 'input'
                },
                employeeStatus: {
                    name: '员工状态',
                    type: 'select',
                    options: [
                        {
                            value: 'on',
                            label: '在职'
                        },
                        {
                            value: 'apprenticeship',
                            label: '见习'
                        },
                        {
                            value: 'probation',
                            label: '试用'
                        },
                        {
                            value: 're-employ',
                            label: '返聘'
                        },
                        {
                            value: 'unemployed',
                            label: '待岗'
                        },
                        {
                            value: 'dismiss',
                            label: '解聘'
                        },
                        {
                            value: 'off',
                            label: '离职'
                        },
                        {
                            value: 'retire',
                            label: '退休'
                        },
                        {
                            value: 'discharge',
                            label: '离休'
                        },
                        {
                            value: 'retreat',
                            label: '内退'
                        },
                        {
                            value: 'sick',
                            label: '病休'
                        },
                        {
                            value: 'adjusted',
                            label: '可调配'
                        },
                        {
                            value: 'died',
                            label: '身故'
                        },
                        {
                            value: 'co-management',
                            label: '共同管理'
                        }
                    ]
                },
                Id: {
                    name: '证件号码',
                    type: 'input'
                },
                organization: {
                    name: '组织',
                    type: 'input'
                },
                department: {
                    name: '部门',
                    type: 'input'
                }
            })
            this.data = filterData
        },


        //初始化表格
        async initTableData() {
            // 发送请求获取表格数据 
            // let data = await Request.requestForm(
            //   Request.GET,
            //   '/archives/archivesInfo/',
            //   data
            // )
            // const rows= data.data.rows
            this.tableOperations = [
                { name: "导出" },
                { name: "过滤" }
            ]
            const rows = [
                {
                    id: 10001,
                    name: '彭于晏',
                    age: 26,
                    organization: '集团总部',
                    department: '企业部门',
                    position: '总规划师',
                    job: '培训管理',
                    certificateId: 140821199103011618,
                    phoneNumber: 15035052120,
                    state: '在职'
                },
                {
                    id: 10002,
                    name: '甄子丹',
                    age: 26,
                    organization: '集团总部',
                    department: '企业部门',
                    position: '总规划师',
                    job: '培训管理',
                    certificateId: 140821199103011618,
                    phoneNumber: 15035052120,
                    state: '在职'
                },
                {
                    id: 10003,
                    name: '彭于晏',
                    age: 26,
                    organization: '集团总部',
                    department: '企业部门',
                    position: '总规划师',
                    job: '培训管理',
                    certificateId: 140821199103011618,
                    phoneNumber: 15035052120,
                    state: '在职'
                },
                {
                    id: 10004,
                    name: '彭于晏',
                    age: 26,
                    organization: '集团总部',
                    department: '企业部门',
                    position: '总规划师',
                    job: '培训管理',
                    certificateId: 140821199103011618,
                    phoneNumber: 15035052120,
                    state: '在职'
                },
                {
                    id: 10005,
                    name: '彭于晏',
                    age: 26,
                    organization: '集团总部',
                    department: '企业部门',
                    position: '总规划师',
                    job: '培训管理',
                    certificateId: 140821199103011618,
                    phoneNumber: 15035052120,
                    state: '在职'
                },
                {
                    id: 10006,
                    name: '彭于晏',
                    age: 26,
                    organization: '集团总部',
                    department: '企业部门',
                    position: '总规划师',
                    job: '培训管理',
                    certificateId: 140821199103011618,
                    phoneNumber: 15035052120,
                    state: '在职'
                },
                {
                    id: 10007,
                    name: '彭于晏',
                    age: 26,
                    organization: '集团总部',
                    department: '企业部门',
                    position: '总规划师',
                    job: '培训管理',
                    certificateId: 140821199103011618,
                    phoneNumber: 15035052120,
                    state: '在职'
                }]
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
                {
                    label: '员工姓名',
                    name: 'name',
                    type: String
                },
                {
                    label: '员工编号',
                    name: 'ID',
                    type: Array,
                    //如果是选项请配置以下属性
                    options: [
                        {
                            id: 1,
                            optionData: '111'
                        },
                        {
                            id: 2,
                            optionData: '222'
                        }
                    ]
                },
                {
                    label: '备注',
                    name: 'remark',
                    type: 'Text'
                }
            ])
            this.dataitem = rows
        },
        //请求待定
        addData(val) {
            this.tableData.push(val)
        },

        editInfo() {
            // 发送请求获取员工信息数据
            // let data = await Request.requestForm(
            //   Request.GET,
            //   '/archives/archivesInfo/',
            //   data
            // )
            // const rows= data.data.rows
            const rows = reactive({
              
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
    }
})

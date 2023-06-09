import { defineStore } from 'pinia'
// import Request from '@/apis/request'

export const useOnReminderStore = defineStore('onFileReminder', {
    state: () => ({
        //记录侧边栏菜单
        menus: null,
        //记录表格表名
        tableTitle: null,
        tableOperations: [],
        //记录表单数据
        xmlData: [
            { id: 1, name: '档案编号', prop: 'id' },
            { id: 2, name: '管理单位', prop: 'name' },
            { id: 3, name: '档案保管地', prop: 'dabgd' },
            { id: 4, name: '档案室', prop: 'archivesRoom' },
            { id: 5, name: '档案状态', prop: 'fileStatus' },
            { id: 6, name: '员工编号', prop: 'employeeNumber' },
            { id: 7, name: '员工姓名', prop: 'employeeName' },
            { id: 8, name: '所属单位', prop: 'unit' },
            { id: 9, name: '员工状态', prop: 'state' },
            { id: 10, name: '操作列', prop: 'action' },
        ],
        //记录表格数据
        tableData: null,
        //用户信息
        userData: null,
        // 每页数据条数
        pageSize: [],
        //总数据条数
        total: null,
        //当前页
        currentPage: null,
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
        },

        // 根据过滤器结果，发送请求-    //分页查询档案列表
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
                employeeNum: {
                    name: '员工编号',
                    type: 'input'
                },
                employeeName: {
                    name: '员工姓名',
                    type: 'input'
                },
                achievesNum: {
                    name: '员工姓名',
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
                achievesStatus: {
                    name: '档案状态',
                    type: 'select',
                    options: [
                        {
                            value: 'effect',
                            label: '有效'
                        },
                        {
                            value: 'noEffect',
                            label: '无效'
                        }]
                },
                borrowStatus: {
                    name: '档案借阅状态',
                    type: 'select',
                    options: [
                        {
                            value: 'borrowing',
                            label: '借阅中'
                        },
                        {
                            value: 'returned',
                            label: '已归还'
                        }]
                },

            })
            this.data = filterData
            //将筛选的数据复制给表格数据
            // this.tableData=this.data 
        },

        initTableData() {
            // 发送请求获取表格数据
            // let data = await Request.requestForm(
            //   Request.GET,
            //   '/archives/onFileReminder/',
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
                    unit: '培训管理',
                    state: '有效',
                    action: '调出档案'
                },
                {
                    id: '002',
                    name: '某大型集团公司',
                    dabgd: '公司本部',
                    archivesRoom: '档案室1111上层1',
                    fileStatus: '有效',
                    employeeNumber: 1921,
                    employeeName: 'sxj',
                    unit: '培训管理',
                    state: '有效',
                    action: '调出档案'
                },
            ]
            this.tableTitle = '非员工在档提醒'
            this.tableOperations = [
                {
                    name: '新增'
                },
            ]
            this.tableData = rows
        },
        addData(val) {
            this.tableData.push(val)
        },
        editInfo() {
            // 发送请求获取表格数据
            // let data = await Request.requestForm(
            //   Request.GET,
            //   '/archives/archivesInfo/',
            //   null
            // )
            // this.userData = data.data
            this.userData = {
                //员工信息
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
                    unitTime: '2022-01-18',
                    technicalTitle: '高级技工',
                    practisingCertificate: '高级技工证',
                    grade: '组长',
                    mobileNumber: '15000244488',
                    cjgzsj: '2022-01-18',
                    eMail: '1111158@193.com',
                    highestDegree: '硕士研究生',
                    firstDegree: '硕士研究生',
                    url: 'https://fuss10.elemecdn.com/e/5d/4a731a90594a4af544c0c25941171jpeg.jpeg'
                },
                //教育信息
                educationInfo: [
                    {
                        degree: '硕士',
                        date: '2016-05-03',
                        admission: '2018-05-03',
                        graduation: '2021-05-03',
                        school: '北京大学',
                        firstDiscipline: '土木工程',
                        major: '土木工程',
                        studyMode: '正规高等院校（统招）',
                        category: '公办院校',
                        ifFirstDegree: '是',
                        ifHighestDegree: '是'
                    },
                    {
                        degree: '博士',
                        date: '2016-05-03',
                        admission: '2018-05-03',
                        graduation: '2021-05-03',
                        school: '北京大学',
                        firstDiscipline: '土木工程',
                        major: '土木工程',
                        studyMode: '正规高等院校（统招）',
                        category: '公办院校',
                        ifFirstDegree: '是',
                        ifHighestDegree: '是'
                    }
                ],
                //工作履历
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
                //补充信息
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
                //奖惩信息
                reandpuInfo: [
                    {
                        rewardsAndPunishmentsTime: '2021-05-03',
                        name: '3355',
                        classification: '奖励',
                        unit: '北京市'
                    }
                ]
            }
        },
    })

import { defineStore } from 'pinia'
import Request from '@/apis/request'

//侧边栏数据
const asideMenus = reactive([
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
  {
    path: '/sample/pagination',
    text: '分页',
    icon: 'user'
  }
])

//表单数据
const xmlData = [
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
]

//注入表格数据
const tableData = [
  {
    id: 001,
    name: '某大型集团公司',
    dabgd: '公司本部',
    archivesRoom: '档案室1111上层1',
    fileStatus: '有效',
    employeeNumber: 1921,
    employeeName: 'sxj',
    state: '有效',
    unit: '培训管理',
    months: 5,
    loanStatus: ''
  },
  {
    id: 002,
    name: '某大型集团公司',
    dabgd: '公司本部',
    archivesRoom: '档案室1111上层1',
    fileStatus: '有效',
    employeeNumber: 1921,
    employeeName: 'sxj',
    state: '有效',
    unit: '培训管理',
    months: 11,
    loanStatus: ''
  }
]

//编辑信息
const userData = reactive({
  //基础信息
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
})
//新增表单所需栏目
const dataitem = reactive([
  {
    label:'员工姓名',
    name:'name',
    type:String,
  },
  {
    label:'员工编号',
    name:'ID',
    type:Array,
    //如果是选项请配置以下属性
    options:[
      {
        id:1,
        optionData:"111"
      },
      {
        id:2,
        optionData:"222"
      },
    ]   
  },
  {
    label:'备注',
    name:'remark',
    type:'Text',
  },
])


export const useInfoStore = defineStore('archivesInfo', {
  state: () => ({
    //记录侧边栏菜单
    menus: null,
    //配置功能按键
    tableOperations: [{ name: '新增' }],
    //新增表单所需栏目配置
    dataitem: [],
    //记录表格表名
    tableTitle: '',
    //新增按钮表单表名
    addTitle: '',
    //记录表单数据
    xmlData: xmlData,
    //记录表格数据
    tableData: null,
    //用户信息
    userData: null
    //每页数据条数
    pageSizes: [],
    //总数据条数
    total: null,
  }),
  actions: {
    //加载侧边栏菜单
    async asideData() {
      //发送请求获取表单所需栏目
      // let data = await Request.requestForm(
      //   Request.GET,
      //   '/archives/archivesInfo/',
      //   null
      // )
      // this.dataitem = data.data
      this.menus = asideMenus
    },

    //根据搜索内容筛选数据
    filter(val) {
      console.log(`output->`, val)
    },

    async getData(val) {
      //发送请求获取表单所需栏目
      // let data = await Request.requestForm(
      //   Request.GET,
      //   '/archives/archivesInfo/',
      //   null
      // )
      // this.dataitem = data.data
      //写保存数据的逻辑
      this.dataitem=dataitem
      this.dataitem.push(val)
    },

    async savaTableData() {
      // 发送请求获取表格数据
      // let data = await Request.requestForm(
      //   Request.GET,
      //   '/archives/archivesInfo/',
      //   null
      // )
      // this.tableData = data.data
      this.tableData = tableData
    },
    async editInfo(){
      // 发送请求获取表格数据
      // let data = await Request.requestForm(
      //   Request.GET,
      //   '/archives/archivesInfo/',
      //   null
      // )
      // this.userData = data.data
      this.userData=userData
      provide('userData', userData)
    }
    
  }
})

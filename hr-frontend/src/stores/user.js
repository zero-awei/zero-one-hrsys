import { defineStore } from 'pinia'
import Request from '@/apis/request'
// 测试菜单数据
let testMenus = [
  {
    id: 0,
    text: '门户首页',
    icon: 'DataAnalysis',
    path: '/pimportalview'
  },
  {
    id: 1,
    text: '人员信息',
    icon: 'IconSetting',
    children: [
      {
        id: 2,

        text: '员工信息',
        path: '/employee',
        icon: 'IconSetting',
        pid: 1
      },
      {
        id: 3,

        text: '自助信息审核',
        path: '/review',
        icon: 'IconSetting',
        pid: 1
      },
      {
        id: 4,

        text: '黑名单',
        path: '/blacklist',
        icon: 'IconSetting',
        pid: 1
      }
    ]
  },
  {
    id: 0,
    text: '人员花名册',
    icon: 'IconSetting',
    children: [
      {
        id: 5,
        text: '人员花名册',
        path: '/roster',
        icon: 'IconSetting',
        pid: 1
      },
      {
        id: 6,
        text: '见习员工',
        path: '/trainee',
        icon: 'IconSetting',
        pid: 1
      },
      {
        id: 0,
        text: '试用员工',
        icon: 'IconSetting',
        path: '/syqyggridview'
      },
      {
        id: 1,
        text: '离(退)休人员',
        icon: 'IconSetting',
        path: '/ltxyggridview'
      },
      {
        id: 2,
        text: '离职人员',
        icon: 'IconSetting',
        path: '/lzyghmcgridview'
      },
      {
        id: 3,
        text: '借调员工',
        icon: 'IconSetting',
        path: '/jdryhmcgridview'
      },
      {
        id: 4,

        text: '挂职员工',
        icon: 'IconSetting',
        path: '/gzryhmcgridview'
      }
    ]
  },

  {
    id: 2,
    text: '合同管理',
    icon: 'IconUser',
    children: [
      {
        id: 2,
        text: '劳务派遣公司',
        path: '/dispatch',
        icon: 'IconUser',
        pid: 2
      },
      {
        id: 3,
        text: '合同信息',
        path: '/contract',
        icon: 'IconUser',
        pid: 2
      },
      {
        id: 4,
        text: '初签(续签)提醒',
        path: '/initsigning',
        icon: 'IconUser',
        pid: 2
      },
      {
        id: 5,
        text: '终止提醒',
        path: '/termination',
        icon: 'IconUser',
        pid: 2
      }
    ]
  },
  {
    id: 9,
    text: '离(退)休管理',
    icon: 'IconUser',
    children: [
      {
        id: 2,
        text: '离(退)休人员',
        path: '/retiree',
        icon: 'IconUser',
        pid: 2
      },
      {
        id: 3,
        text: '费用台账',
        path: '/expense',
        icon: 'IconUser',
        pid: 2
      }
    ]
  },
  {
    id: 2,
    text: '合同管理',
    icon: 'IconUser',
    children: [
      {
        id: 2,
        text: '劳务派遣公司',
        path: '/dispatch',
        icon: 'IconUser',
        pid: 2
      },
      {
        id: 3,
        text: '合同信息',
        path: '/contract',
        icon: 'IconUser',
        pid: 2
      },
      {
        id: 4,
        text: '初签(续签)提醒',
        path: '/initsigning',
        icon: 'IconUser',
        pid: 2
      },
      {
        id: 5,
        text: '终止提醒',
        path: '/termination',
        icon: 'IconUser',
        pid: 2
      }
    ]
  },
  {
    id: 3,
    text: '订单管理',
    icon: 'IconTickets',
    children: [
      {
        id: 2,
        text: '订单管理1',
        path: '/un-21',
        icon: 'IconTickets',
        pid: 3
      },
      {
        id: 3,
        text: '订单管理2',
        path: '/un-22',
        icon: 'IconTickets',
        pid: 3
      },
      {
        id: 4,
        text: '订单管理3',
        path: '/un-23',
        icon: 'IconTickets',
        pid: 3
      },
      {
        id: 5,
        text: '订单管理4',
        path: '/un-24',
        icon: 'IconTickets',
        pid: 3
      },
      {
        id: 6,
        text: '订单管理5',
        path: '/un-25',
        icon: 'IconTickets',
        pid: 3
      }
    ]
  },
  {
    id: 4,
    text: '标准化数据设置',
    icon: 'IconTickets',
    children: [
      {
        id: 2,
        text: '订单管理1',
        path: '/un-31',
        icon: 'IconTickets',
        pid: 4
      },
      {
        id: 3,
        text: '订单管理2',
        path: '/un-32',
        icon: 'IconTickets',
        pid: 4
      },
      {
        id: 4,
        text: '岗位(技能)证书',
        path: '/postcertificateview',
        icon: 'IconTickets',

        pid: 4
      },
      {
        id: 5,

        text: '职称目录',
        path: '/jobtitlecatalog',
        icon: 'IconTickets',

        pid: 4
      },
      {
        id: 6,

        text: '档案室',
        path: '/archives',
        icon: 'IconTickets',
        pid: 4
      },
      {
        id: 2,
        text: '合同类别',
        path: '/contractCatrgory',
        icon: 'IconTickets',
        pid: 3
      },
      {
        id: 3,
        text: '合同类型',
        path: '/contractType',
        icon: 'IconTickets',
        pid: 3
      },
      {
        id: 4,
        text: '执业资格证书',
        path: '/practiceCertificate',
        icon: 'IconTickets',
        pid: 3
      }
    ]
  }
]

export const userStore = defineStore('user', {
  state: () => ({
    // 记录token
    token: null,
    // 记录refreshToken
    refreshToken: null,
    // 保存一个标识信息，指示登陆后需要加载的初始化数据是否完成
    loaded: false,
    // 保存当前用户
    user: null,
    // 菜单数据
    // menus: []
    menus: testMenus
  }),
  getters: {
    // 获取token
    getToken: (state) => state.token || localStorage.getItem('token'),
    // 是否已加载
    isLoaded: (state) => state.loaded,
    // 获取当前用户
    getUser: (state) => state.user,
    // 获取菜单
    getMenus: (state) => state.menus
  },
  actions: {
    // 加载用户
    async loadUser() {
      // 发送获取当前用户信息请求
      let data = await Request.requestForm(
        Request.GET,
        '/login/current-user',
        null
      )
      this.user = data.data
    },
    // 加载菜单
    async loadMenus() {
      //TODO[TEST_CODE]:此处写测试数据设定
      //this.menus = testMenus

      // 发送获取菜单请求
      let data = await Request.requestForm(
        Request.GET,
        '/login/get-menus',
        null
      )
      this.menus = data.data
    },
    // 加载刷新凭证
    loadRefreshToken() {
      if (!this.refreshToken)
        this.refreshToken = localStorage.getItem('refreshToken')
    },
    // 刷新token
    async reloadToken() {
      // 先加载刷新凭证
      this.loadRefreshToken()
      // 发送刷新凭证请求
      let data = await Request.requestForm(
        Request.POST,
        '/login/refresh-token',
        {
          refreshToken: this.refreshToken,
          clientId: import.meta.env.VITE_API_URL
        }
      )
      //设置Token相关属性
      this.setToken(data.data)
    },
    // 设置是否加载完成
    setLoaded(loaded) {
      this.loaded = loaded
    },
    // 设置token
    setToken(data) {
      this.token = data.token
      this.refreshToken = data.refreshToken
      localStorage.setItem('token', this.token)
      localStorage.setItem('refreshToken', this.refreshToken)
    },
    // 重置数据
    resetSaveData() {
      this.loaded = false
      this.user = null
      this.token = null
      this.refreshToken = null
      localStorage.removeItem('token')
      localStorage.removeItem('refreshToken')
    }
  }
})

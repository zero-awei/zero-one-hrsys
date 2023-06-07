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
    icon: 'User',
    children: [
      {
        id: 2,
        text: '员工信息',
        path: '/employee',
        icon: 'User'
      },
      {
        id: 3,
        text: '自助信息审核',
        path: '/review',
        icon: 'Tickets'
      },
      {
        id: 4,
        text: '黑名单',
        path: '/blacklist',
        icon: 'Postcard'
      }
    ]
  },
  {
    id: 5,
    text: '人员花名册',
    icon: 'Notebook',
    children: [
      {
        id: 6,
        text: '人员花名册',
        path: '/roster',
        icon: 'Notebook'
      },
      {
        id: 7,
        text: '见习员工',
        path: '/trainee',
        icon: 'User'
      },
      {
        id: 8,
        text: '试用员工',
        icon: 'User',
        path: '/syqyggridview'
      },
      {
        id: 9,
        text: '离(退)休人员',
        icon: 'User',
        path: '/retireStaff'
      },
      {
        id: 10,
        text: '离职人员',
        icon: 'User',
        path: '/leaveStaff'
      },
      {
        id: 11,
        text: '借调员工',
        icon: 'User',
        path: '/jdryhmcgridview'
      },
      {
        id: 12,
        text: '挂职员工',
        icon: 'User',
        path: '/temporyStaff'
      }
    ]
  },

  {
    id: 13,
    text: '合同管理',
    icon: 'DocumentCopy',
    children: [
      {
        id: 14,
        text: '劳务派遣公司',
        path: '/dispatch',
        icon: 'SetUp'
      },
      {
        id: 15,
        text: '合同信息',
        path: '/contract',
        icon: 'Files'
      },
      {
        id: 16,
        text: '初签(续签)提醒',
        path: '/initsigning',
        icon: 'Bell'
      },
      {
        id: 17,
        text: '终止提醒',
        path: '/termination',
        icon: 'Bell'
      }
    ]
  },
  {
    id: 18,
    text: '档案管理',
    icon: 'CopyDocument',
    children: [
      {
        id: 19,
        text: '档案信息',
        path: '/archivesinfo',
        icon: 'Document'
      },
      {
        id: 20,
        text: '非员工在档提醒',
        path: '/onfilereminder',
        icon: 'Bell'
      },
      {
        id: 21,
        text: '员工不在档提醒',
        path: '/outfilereminder',
        icon: 'Bell'
      },
      {
        id: 22,
        text: '档案转出记录',
        path: '/filetransferrecord',
        icon: 'DocumentRemove'
      }
    ]
  },
  {
    id: 23,
    text: '证书管理',
    icon: 'Files',
    children: [
      {
        id: 24,
        text: '证书信息',
        path: '/certificateinfo',
        icon: 'Tickets'
      }
    ]
  },
  {
    id: 25,
    text: '职称管理',
    icon: 'Medal',
    children: [
      {
        id: 26,
        text: '职称信息',
        path: '/jobtitleinfo',
        icon: 'GoldMedal'
      }
    ]
  },
  {
    id: 27,
    text: '出(国)境管理',
    icon: 'Guide',
    children: [
      {
        id: 28,
        text: '因公出(国)境',
        path: '/businessabroad',
        icon: 'Van'
      },
      {
        id: 29,
        text: '因私出(国)境',
        path: '/privateabroad',
        icon: 'Bicycle'
      }
    ]
  },
  {
    id: 30,
    text: '离(退)休管理',
    icon: 'Postcard',
    children: [
      {
        id: 31,
        text: '离(退)休人员',
        path: '/retiree',
        icon: 'IconUser'
      },
      {
        id: 32,
        text: '费用台账',
        path: '/expense',
        icon: 'Tickets'
      }
    ]
  },
  {
    id: 33,
    text: '标准化数据设置',
    icon: 'SetUp',
    children: [
      {
        id: 34,
        text: '岗位(技能)证书',
        path: '/postcertificateview',
        icon: 'IconTickets'
      },
      {
        id: 35,
        text: '职称目录',
        path: '/jobtitlecatalog',
        icon: 'IconTickets'
      },
      {
        id: 36,
        text: '档案室',
        path: '/archives',
        icon: 'IconTickets'
      },
      {
        id: 37,
        text: '合同类别',
        path: '/contractCatrgory',
        icon: 'IconTickets'
      },
      {
        id: 38,
        text: '合同类型',
        path: '/contractType',
        icon: 'IconTickets'
      },
      {
        id: 39,
        text: '执业资格证书',
        path: '/practiceCertificate',
        icon: 'IconTickets'
      }
    ]
  },
  {
    id: 40,
    text: '系统管理',
    icon: 'Orange',
    children: [
      {
        id: 41,
        text: '权限管理',
        path: '/rightsmanage',
        icon: 'IconSetting'
      },
      {
        id: 42,
        text: ' 菜单管理',
        path: '/menumanage',
        icon: 'IconSetting'
      },
      {
        id: 43,
        text: '角色管理',
        path: '/rolesmanage',
        icon: 'IconSetting'
      },
      {
        id: 44,
        text: '用户管理',
        path: '/usersmanage',
        icon: 'IconSetting'
      }
    ]
  },
  {
    id: 45,
    text: '组织管理',
    icon: 'TakeawayBox',
    children: [
      {
        id: 46,
        text: '组织信息',
        path: '/orginfo',
        icon: 'CreditCard'
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

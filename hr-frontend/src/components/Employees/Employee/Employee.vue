<template>
  <div class="employee">
    <div class="box h1">
      <div>
        <div class="right">员工姓名</div>
        <div class="left">{{ ename }}</div>
        <br />
        <div class="right">证件类型</div>
        <div class="left">{{ IDType }}</div>
        <br />
        <div class="right">出生日期</div>
        <div class="left">{{ birth }}</div>
        <br />
        <div class="right">性别</div>
        <div class="left">{{ sex }}</div>
        <br />
        <div class="right">籍贯</div>
        <div class="left">{{ birthplace }}</div>
      </div>
      <div>
        <div class="right">员工编号</div>
        <div class="left">{{ empno }}</div>
        <br />
        <div class="right">证件号码</div>
        <div class="left">{{ IDNumber }}</div>
        <br />
        <div class="right">年龄</div>
        <div class="left">{{ age }}</div>
        <br />
        <div class="right">民族</div>
        <div class="left">{{ nation }}</div>
        <br />
        <div class="right">婚姻状况</div>
        <div class="left">{{ marriage }}</div>
      </div>
      <div>
        <div class="right">照片</div>
        <div class="left">
          <el-avatar shape="square" :size="100" :fit="fit" :src="url" />
        </div>
      </div>
    </div>
    <div class="box h2">
      <div>
        <div class="right">政治面貌</div>
        <div class="left">{{ politicalLandscape }}</div>
        <br />
        <div class="right">到本单位时间</div>
        <div class="left">{{ unitTime }}</div>
        <br />
        <div class="right">技术职称</div>
        <div class="left">{{ technicalTitle }}</div>
        <br />
        <div class="right">执业证书</div>
        <div class="left">{{ practisingCertificate }}</div>
      </div>
      <div>
        <div class="right">职级</div>
        <div class="left">{{ grade }}</div>
        <br />
        <div class="right">手机号码</div>
        <div class="left">{{ mobileNumber }}</div>
        <br />
        <div class="right">最高学历</div>
        <div class="left">{{ highestDegree }}</div>
      </div>
      <div>
        <div class="right">参加工作时间</div>
        <div class="left">{{ cjgzsj }}</div>
        <br />
        <div class="right">电子邮箱</div>
        <div class="left">{{ eMail }}</div>
        <br />
        <div class="right">第一学历</div>
        <div class="left">{{ firstDegree }}</div>
      </div>
    </div>
  </div>
</template>
<script>
export default {
  data() {
    return {
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
    }
  }
}
</script>

<style lang="scss">
.box {
  display: flex;
}
.h1 {
  height: 250px;
}
.h2 {
  height: 200px;
}
.box div {
  flex: 1;
  height: 50px;
}
.left {
  padding-left: 8px;
  float: left;
  width: 70%;
  text-align: left;
}
.right {
  float: left;
  width: 30%;
  text-align: right;
}
</style>

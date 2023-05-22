<template>
  <div class="employee">
    <div class="box h1">
      <div>
        <div class="right">员工姓名</div>
        <div class="left">{{ basicInfo.ename }}</div>
        <br />
        <div class="right">证件类型</div>
        <div class="left">{{ basicInfo.IDType }}</div>
        <br />
        <div class="right">出生日期</div>
        <div class="left">{{ basicInfo.birth }}</div>
        <br />
        <div class="right">性别</div>
        <div class="left">{{ basicInfo.sex }}</div>
        <br />
        <div class="right">籍贯</div>
        <div class="left">{{ basicInfo.birthplace }}</div>
      </div>
      <div>
        <div class="right">员工编号</div>
        <div class="left">{{ basicInfo.empno }}</div>
        <br />
        <div class="right">证件号码</div>
        <div class="left">{{ basicInfo.IDNumber }}</div>
        <br />
        <div class="right">年龄</div>
        <div class="left">{{ basicInfo.age }}</div>
        <br />
        <div class="right">民族</div>
        <div class="left">{{ basicInfo.nation }}</div>
        <br />
        <div class="right">婚姻状况</div>
        <div class="left">{{ basicInfo.marriage }}</div>
      </div>
      <div>
        <div class="right">照片</div>
        <div class="left">
          <el-avatar
            shape="square"
            :size="100"
            fit="fit"
            :src="basicInfo.url"
          />
        </div>
      </div>
    </div>
    <div class="box h2">
      <div>
        <div class="right">政治面貌</div>
        <div class="left">{{ basicInfo.politicalLandscape }}</div>
        <br />
        <div class="right">到本单位时间</div>
        <div class="left">{{ basicInfo.unitTime }}</div>
        <br />
        <div class="right">技术职称</div>
        <div class="left">{{ basicInfo.technicalTitle }}</div>
        <br />
        <div class="right">执业证书</div>
        <div class="left">{{ basicInfo.practisingCertificate }}</div>
      </div>
      <div>
        <div class="right">职级</div>
        <div class="left">{{ basicInfo.grade }}</div>
        <br />
        <div class="right">手机号码</div>
        <div class="left">{{ basicInfo.mobileNumber }}</div>
        <br />
        <div class="right">最高学历</div>
        <div class="left">{{ basicInfo.highestDegree }}</div>
      </div>
      <div>
        <div class="right">参加工作时间</div>
        <div class="left">{{ basicInfo.cjgzsj }}</div>
        <br />
        <div class="right">电子邮箱</div>
        <div class="left">{{ basicInfo.eMail }}</div>
        <br />
        <div class="right">第一学历</div>
        <div class="left">{{ basicInfo.firstDegree }}</div>
      </div>
    </div>
  </div>
</template>
<script setup>
import { inject } from 'vue'
const userData = inject('userData')
let { basicInfo } = userData
</script>

<style lang="scss">
.box {
  display: flex;
}
// .h1 {
//   height: 250px;
// }
.h2 {
  padding-top: 50px;
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

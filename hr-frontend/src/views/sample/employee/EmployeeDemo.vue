<template>
  <Employees></Employees>
</template>

<script setup>
import Employees from '@/components/employees/Employees.vue'
import { reactive, provide } from 'vue'
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
provide('userData', userData)
</script>

<style lang="scss" scoped></style>

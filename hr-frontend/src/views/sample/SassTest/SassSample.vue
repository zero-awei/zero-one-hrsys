<template>
  <div class="hr-box">
    <div class="hr-box__inner">
      <span class="hr-box__inner--disabled">某元素</span>
    </div>
  </div>
</template>

<script setup></script>

<style lang="scss" scoped>
// 块级层：某一整块区域，最外层的容器
@include block(box) {
  width: 500px;
  height: 500px;
  background-color: skyblue;
  // 元素层：块级层内的某一部分
  @include element(inner) {
    text-align: center;
    line-height: 500px;
    font-size: 50px;
    color: #fff;
    font-weight: 700;
    // 修饰层：表示状态
    @include modifier(disabled) {
      color: #999;
      background-color: #ccc;
    }
  }
}
</style>

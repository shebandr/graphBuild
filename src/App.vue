<template>
  <div>
    <my-input @buildGraph="buildGraph" v-show="inputField"></my-input>
    <graph-canvas v-show="inputField==false" :message='message'></graph-canvas>
  </div>
</template>

<script>
import MyInput from "@/components/MyInput.vue"
import GraphCanvas from "@/components/GraphCanvas.vue"
export default {
  components: {
    MyInput, GraphCanvas
  },
   props: ['dotes'],
  name: 'App',
  data() {
    return {
      message: '',
      inputField: true
    }
  },
  methods: {
    buildGraph(data) {
      this.message = data
      this.inputField = false
      console.log(data)
    }
  }
}
</script>

<style>
</style>

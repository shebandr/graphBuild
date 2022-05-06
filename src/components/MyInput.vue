<template>
  <div>
    <form v-on:submit.prevent="onSubmit" class="description">
      <div class="textWindow">
        <span
          class="description"
        >Построение графика по входным данным, по оX изначально идет отсчет до 1000 с шагом в 10, вносить данные формата "100 200 300 \n 120 240 360 \n 140 280 420"</span>
        <button @click="buildGraph">Построить график по данным</button>
      </div>
      <input type="file" name="imported-file" accept=".txt" @change="fileHandler(this);">
      <textarea v-model="message" placeholder="введите данные"></textarea>
    </form>
  </div>
</template>

<script>
export default {

  data() {
    return {
      message: ''
    }
  },
  methods: {
    buildGraph() {
      this.$emit('buildGraph',
        this.message
      )
    },
    fileHandler(input) {
      let file = input.files[0];
      console.log(file)
      let reader = new FileReader();
      reader.readAsText(file);
      reader.onload = function () {
        var fileArr = reader.result.split('\n');
        reader.onerror = function () {
          console.log(reader.error);
        };
        console.log(fileArr)
      }
    }
  }
}
</script>

<style>
.textWindow {
  margin: 0 auto;
  height: 70px;
  width: 800px;
  border: gray 3px solid;
  text-align: center;
  border-radius: 30px;
}
.description {
  display: block;
}
textarea {
  margin: 0 auto;
  height: 500px;
  width: 1890px;
  border: gray 3px solid;
  text-align: center;
  border-radius: 30px;
}
</style>
<template>
  <div class="col-md-6 col-sm-12">
    <div class="institute-login-form">
      <form @submit.prevent="auth">
        <div class="form-group">
          <model-select required ref="select"
                        :options="inst_options"
                        v-model="institute"
                        placeholder="Institute"
          >
          </model-select>
        </div>
        <div class="form-group" v-on:focus="get_groups">
          <model-select required ref="select"
                        :options="group_options"
                        v-model="group"
                        placeholder="Group">
          </model-select>
        </div>
        <div class="form-group">
          <model-select required ref="select"
                        :options="snp_options"
                        v-model="snp"
                        placeholder="Surname Name Patronymic">
          </model-select>
        </div>
        <div class="form-group">
          <input type="password" required class="form-control" placeholder="Password" v-model="password">
        </div>
        <div class="form-group">
          <label class="form-control">
            <input type="checkbox" v-model="save_checked"/>
            Keep password?
          </label>
        </div>
        <button title="Not implemented yet." type="submit" class="btn btn-black" disabled>Submit</button>
      </form>
    </div>
  </div>


</template>

<script>
import {ModelSelect} from 'vue-search-select'
import axios from 'axios';
import 'vue-search-select/dist/VueSearchSelect.css'

export default {
  name: "InstituteLogin",
  components: {
    ModelSelect
  },
  data() {
    return {
      institute: null,
      group: null,
      snp: null,
      password: '',
      save_checked: false,
      inst_options: [],
      group_options: [],
      snp_options: []
    }
  },
  // }, data() {
  //     return {
  //         inst_options: [
  //             {value: '1', text: 'Информационных технологий'}
  //         ],
  //         institute: '',
  //         group_options: [
  //
  //             {value: '1', text: 'ИКБО-XX-XX'},
  //             {value: '2', text: 'ИНБО-XX-XX'},
  //             {value: '3', text: 'ИРБО-XX-XX'}
  //
  //         ],
  //         group: '',
  //         snp_options: [
  //             {value: '1', text: 'Somebody XYZ'},
  //             {value: '2', text: 'Somebody ABC'},
  //             {value: '3', text: 'Somebody LOL'}
  //         ],
  //         snp: '',
  //         save_checked: false
  //
  //     }
  //
  // },
  methods:
      {
        get_institutes: async function () {
          let _ = [];
          await axios.get(this.$store.state.api_host + '?method=getInstitutesList').then((response) => {
            response.data.forEach((item) => {
              _.push({
                "value": item.id,
                "text": item.name
              })
            })
            this.inst_options = _;
          })
        },
        get_groups: async function (institute_id) {
          let _ = [];
          await axios.get(this.$store.state.api_host + '?method=getGroupsByInstitute&institute_id=' + institute_id).then((response) => {
            response.data.forEach((item) => {
              _.push({
                "value": item.id,
                "text": item.name
              })
            })
            this.group_options = _;
          })
        },
        get_students: async function (group_id) {
          let _ = [];
          await axios.get(this.$store.state.api_host + '?method=getStudentsByGroup&group_id=' + group_id).then((response) => {
            response.data.forEach((item) => {
              _.push({
                "value": item.id,
                "text": `${item.surname} ${item.name} + ${item.patronymic}`
              })
            })
            this.group_options = _;
          })
        },
        auth: async function () {
          // Non Implemented
          //return true;
          this.$store.dispatch('login', {
            'institute': this.institute,
            'group': this.group,
            'snp': this.snp,
            'password': this.password
          })
              .then(() => this.$router.push('/'))
              .catch(err => console.log(err))
        }
      },
  async mounted() {
    //await WS.methods.connect();
    await this.get_institutes();
  },
  watch:{
    institute: async function (value){
      await this.get_groups(value);
    }
  }
}
</script>

<style scoped>
.btn-black {
  background-color: #000 !important;
  color: #fff !important;
  width: 50%;
}


</style>
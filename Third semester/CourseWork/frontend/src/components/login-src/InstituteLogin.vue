<template>

    <div class="col-md-6 col-sm-12">
        <div class="institute-login-form">
            <form @submit.prevent="auth">
                <div class="form-group" v-on:click="get_institutes">
                    <model-select required ref="select"
                                  :options="inst_options"
                                  v-model="institute"
                                  placeholder="Institute"
                    >
                    </model-select>
                </div>
                <div class="form-group">
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
    import WS from "@/components/WS";
    import 'vue-search-select/dist/VueSearchSelect.css'

    export default {
        name: "InstituteLogin",
        props: {
            inst_options: Array,
            group_options: Array,
            snp_options: Array
        },
        components: {
            ModelSelect
        },
        data() {
            return {institute: '', group: '', snp: '', password: '', save_checked: false}
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
                    await WS.methods.sendMessage(JSON.stringify({'action': 'get_inst_list'}))
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
            //await this.get_institutes();
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
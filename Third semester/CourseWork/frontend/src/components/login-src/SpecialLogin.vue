<template>
    <div class="col-md-6 col-sm-12">
        <div class="special-login-form">
            <form @submit.prevent="auth">
                <div class="form-group">
                    <input required type="text" class="form-control" placeholder="Username" v-model="login">
                </div>
                <div class="form-group">
                    <input required type="password" class="form-control" placeholder="Password" v-model="password">
                </div>
                <div class="form-group">
                    <label class="form-control">
                        <input type="checkbox" v-model="save_checked"/>
                        Keep password?
                    </label>
                </div>
                <button type="submit" v-on:click="auth" class="btn btn-black">Submit</button>
            </form>
        </div>
    </div>
</template>

<script>
    export default {
        name: "SpecialLogin",
        data() {
            return {
                login: '',
                password: '',
                save_checked: false
            }
        },
        methods: {
            auth: function () {
                this.$store.dispatch('login', {
                    'login': this.login,
                    'password': this.password

                })
                    .then(() => {
                        this.$store.commit('auth_success', true, this.login)
                        this.$router.push('/')
                    })
                    .catch(err => console.log(err))
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
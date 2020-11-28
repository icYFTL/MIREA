<template>
    <div class="col-md-6 col-sm-12">
        <div class="special-login-form">
            <form @submit.prevent="register">
                <div class="form-group">
                    <input required type="text" class="form-control" placeholder="Username" v-model="login">
                </div>
                <div class="form-group">
                    <input required type="password" class="form-control" placeholder="Password" v-model="password">
                </div>
                <div class="form-group">
                    <input required type="password" class="form-control" placeholder="Retype password" v-model="password_retype">
                </div>
                <button type="submit" class="btn btn-black">Submit</button>
            </form>
        </div>
    </div>
</template>

<script>
    export default {
        name: "SignUpSpecial",
        data() {
            return {
                login: '',
                password: '',
                password_retype: '',
            }
        },
        methods: {
            register: function () { // TODO: Implement
                if (this.password !== this.password_retype){
                    this.$toast.error("Password mismatch")
                    return;
                }

                this.$router.push('/')
                // this.$store.dispatch('login', {
                //     'login': this.login,
                //     'password': this.password
                // })
                //     .then(() => this.$router.push('/'))
                //     .catch(err => console.log(err))
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
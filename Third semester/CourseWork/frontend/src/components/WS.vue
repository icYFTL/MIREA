<template>
<div></div>
</template>

<script>
    export default {
        name: "WS",
        data: function () {
            return {
                connection: null
            }
        },
        methods: {
            sendMessage: async function (message) {
                if (!this.connection || this.connection.isClosing)
                    await this.connect()
                this.connection.send(message)
                console.log(this.connection)
            },
            connect: async function () {
                return new Promise((resolve, reject) => {
                    console.log('[WS] Connection started')
                    this.connection = new WebSocket('ws://localhost:13254')
                    this.connection.repeatDelay = 5;
                    this.connection.onopen = function (event) {
                        console.log(event);
                        console.log('Connection is OK');
                        resolve(this.connection);
                    }
                    this.connection.onmessage = function (event) {
                        console.log(event);
                    }
                    this.connection.onerror = function (event) {
                        console.error(event);
                        reject("BAD");
                    }

                });

            }
        }
    }
</script>

<style scoped>

</style>
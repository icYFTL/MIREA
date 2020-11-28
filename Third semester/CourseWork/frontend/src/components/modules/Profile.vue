<template>
    <div class="profile">
        <div class="upper-space">
            <StudentField class="student-field"></StudentField>
        </div>
    </div>
</template>

<script>
    import StudentField from "./profile-src/StudentField";
    export default {
        name: "Profile",
        components: {StudentField}
    }
</script>

<style lang="scss" scoped>
    //Colors
    $default: #fff;
    .profile{
        display: flex;
        flex-flow: column nowrap;
        width: 100%;
        height: 100%;
        background-color: #171717;
        color: $default;
    }
    .upper-space{
        margin-top: 10px;
    }

    .student-field{

    }

</style>
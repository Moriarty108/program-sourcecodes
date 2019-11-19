const validate = event => {
  event.preventDefault();
  let hUsername = event.target.hUsername.value;
  let wUsername = event.target.wUsername.value;
  let password = event.target.password.value;
  let cPassword = event.target.cPassword.value;
  let usernameRegex = /^[0-9]{8}$/;
  if (hUsername.length === 0 || wUsername.length === 0) {
    alert("Username cannot be blank!");
  }
  if (!(usernameRegex.test(hUsername) && usernameRegex.test(wUsername)))
    alert("Username should be 8 digits long!");

  if (password.length !== 0 || cPassword.length !== 0) {
    if (password !== cPassword)
      alert("Passwords do not match! Please Try Again");
  } else alert("Password must be filled!");
};
